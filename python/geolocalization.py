'''
import urllib.request

url = 'https://iplogger.com/2kxe05'
req = urllib.request.urlopen(url)
res = req.read()

print(res)
'''

# importing geopy library
from geopy.geocoders import Nominatim
 
# calling the Nominatim tool
loc = Nominatim(user_agent="GetLoc")
 
# entering the location name
getLoc = loc.geocode("Gosainganj Lucknow")
 
# printing address
print(getLoc.address)
 
# printing latitude and longitude
print("Latitude = ", getLoc.latitude, "\n")
print("Longitude = ", getLoc.longitude)

'''
import urllib.request

url = 'https://iplogger.com/2kxe05'
req = urllib.request.urlopen(url)
res = req.read()

#print(res)

from gi.repository import Geoclue
clue = Geoclue.Simple.new_sync('something',Geoclue.AccuracyLevel.EXACT,None)
location = clue.get_location()
print(location.get_property('latitude'), location.get_property('longitude'))
'''

'''
import requests

url = 'https://ipapi.co/json/'
res = requests.get(url)
data = res.json()

print("Latitud: {data['latitude']}")
print("Longitud: {data['longitude']}")
'''
