"""
Build protobuf files
"""

import os
import sys
import shutil
import subprocess


protoc = shutil.which("protoc")


def generate_proto(source):
    """
    Call the Protocol Compiler to generate a _pb2.py from the given
    .proto file.  Does nothing if the output already exists and is newer than
    the input.
    """

    output = source.replace(".proto", "").replace("./proto/", ".")

    if not os.path.exists(output) or (
        os.path.exists(source)
        and os.path.getmtime(source) > os.path.getmtime(output)
    ):
        print(" ~ Generating: %s..." % output)

        if not os.path.exists(source):
            sys.stderr.write("Can't find required file: %s\n" % source)
            sys.exit(-1)

        protoc_command = [
            protoc,
            "-I./proto",
            "-I.",
            "--c_out=./libs/proto",
            source,
        ]
        if subprocess.call(protoc_command) != 0:
            sys.exit(-1)


if __name__ == "__main__":
    if protoc is None:
        sys.stderr.write("protoc is not installed!\n")
        sys.exit(-1)

    # Find all the protos
    proto_files = []
    for root, dirs, files in os.walk("proto"):
        for file in files:
            if file.endswith(".proto"):
                proto_files.append(os.path.join(root, file))

    for fn in proto_files:
        generate_proto(fn)
