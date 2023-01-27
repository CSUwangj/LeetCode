# -*- coding: utf-8 -*-

import os

   
for filename in os.listdir('.'):
  src = filename
  dst = filename.split('-')[0]
  
  # rename() function will
  # rename all the files
  os.rename(src, dst + '.in')