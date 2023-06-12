#!/usr/bin/env python3

# alias randsec+="cat mylist.org | grep -A20 'blogqueue high priority' | grep https | cut -d' ' -f 2 > /media/sf_Shared/randsec"

import os
import random

with open("./randsec", "r") as f:
    links = f.read().splitlines()
    rand_link = random.choice(links)
    if "360" not in rand_link:
        print(rand_link)
        os.startfile(rand_link)
