#!user/bin/python

palabras = ["submarino", "sub", "s", "a","subir"]
pattern = "sub"

for item in palabras:
  if item.startswith(pattern):
    print (item)
