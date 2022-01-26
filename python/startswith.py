#!user/bin/python

palabras = ["submarino", "sub", "s", "a","subir"]
pattern = "sub"

def startsw( pals, pat):
  for item in pals:
    if item.startswith(pat):
      print (item)

startsw(palabras, pattern);
