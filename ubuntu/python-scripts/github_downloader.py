#!/usr/bin/env python3
#
# Adapted from: https://github.com/Decad/github-downloader/blob/master/github-downloader.sh

import sys
import os

def usage():
    print("usage: github_downloader.py <github file/folder url>")
    sys.exit()

if len(sys.argv) < 2:
    usage()

url = sys.argv[1]
tokens = url.split("/")

domain = "https://github.com/"
user = tokens[3]
repo_name = tokens[4]
branch = "trunk" if tokens[6] in ["master", "main"] else tokens[6]
target = '/'.join(tokens[7:])
cmd = "svn export {}{}/{}/{}/{}".format(domain, user, repo_name, branch, target)
print(cmd)
os.system(cmd)
