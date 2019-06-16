#!/usr/bin/env python3

import sys;

print ("---");
print ("insns:");
for line in sys.stdin:
  cells = line.split('\t');
  print ("  - mnem: '" + cells[0] + "'");
  print ("    format: " + cells[1]);
  print ("    op2: '" + cells[2] + "'");
  print ("    op1: '" + cells[3] + "'");
  print ("    misc1: '" + cells[4] + "'");
  print ("    misc2: '" + cells[5] + "'");
  print ("    target: '" + cells[8].rstrip() + "'");
