#!/usr/bin/env python

import re
import sys


def panic(msg):
    print("PANIC ::", msg)


""" Fill out re_x such that the following code does not panic.
"""
re_x = re.compile(r"")

for x in ["pit", "spot", "spate", "slap two", "respite"]:
    if not re_x.match(x):
        panic("should match %s" % (x))

for x in ["pt", "Pot", "peat", "part"]:
    m = re_x.match(x)
    if m:
        panic("should NOT match %s" % (x))



