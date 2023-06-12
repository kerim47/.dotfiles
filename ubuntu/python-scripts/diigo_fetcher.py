#!/usr/bin/env python3

from requests.auth import HTTPBasicAuth
from sys import platform
import json
import os
import random
import requests
import subprocess

def prompt_open(link):
    print("Open {}? [y/n/?]".format(link))
    user_input = input().lower()
    if user_input == 'y':
        if "linux" in platform:
            subprocess.Popen(["xdg-open", link],
                           stdout=subprocess.DEVNULL,
                           stderr=subprocess.DEVNULL)
        elif platform == "win32":
            os.startfile(link)
        return True
    elif user_input == 'n':
        return True
    elif user_input == '?':
        match = [x for x in d if x['url'] == choice][0]
        print("title: {}".format(match['title']))
        print("tags: {}\n".format(match['tags']))
    return False

key = os.environ.get('DIIGO_API_KEY')
user = os.environ.get('DIIGO_USER')
passwd = os.environ.get('DIIGO_PASS')
tag = os.environ.get('DIIGO_SEARCH_TAG')

links = []
d = []
for i in range(10):
    print("Loading {} to {}".format(i*100, i*100 + 100))
    api_url = 'https://secure.diigo.com/api/v2/bookmarks?key={}&user={}&filter=all&tags={}&start={}&count=100'.format(key, user, tag, i*100)
    response = requests.get(api_url, auth=HTTPBasicAuth(user, passwd))
    json_response = json.loads(response.text)
    print(json_response)
    print("")
    if len(json_response) == 0:
        break
    links.extend([x.get('url') for x in json_response])
    d.extend(json_response)


choice = random.choice(links)
while True:
    if prompt_open(choice):
        choice = random.choice(links)
