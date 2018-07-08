#!/usr/bin/python3
import requests

request_url = 'https://omniweb.gsfc.nasa.gov/cgi/models/model.cgi'
payload = {
    'model': 'iri', 
    'year' : '2006', 
    # month: '01' ~ '12': January ~ December
    'month' : '12', 
    'day' : '01', 
    # time_flag: '0': Universal; '1': Local
    'time_flag' : '1',
    'hour' : '1.5',
    # geo_flag: '0.': Geographic; '1.': Geomagnetic
    'geo_flag' : '0.',
    # latitude, longitude: variables
    'latitude' : '50.', 
    'longitude' : '40.', 
    'height' : '100.', 
    # profile:
    # '1': Height,km [ 60. - 2000.]
    # '2': Latitude, deg.[-90. - 90.]
    # '3': Longitude, deg.[0. - 360.]
    # '4': Year [1958-2009]
    # '5': Month [1-12]
    # '6': Day of month[1-31]
    # '7': Day of Year[1-366]
    # '8': Hour profileName[1.-24.]
    'profile' : '1',
    'start' : '100.',      
    'stop' : '1000.', 
    'step' : '50.',         
    'sun_n' : '',
    'ion_n' : '',
    'htec_max' : '',
    # imap:
    # '0.': URSI
    # '1.': CCIR
    'imap' : '0.',
    # ib0:
    # '0.': B0 Table
    # '1.': Gulyaeva
    'ib0' : '0.',
    # icomp:
    # '0.': Danilov 95
    # '1.': IRI-86
    'icomp' : '0.',
    # ffof2:
    # '0.': on
    # '1.': off
    'ffof2': '0.',
    # tset:
    # '0.': IRI-95
    # '1.': TTSA-2000
    'tset': '0.', 
    # dreg:
    # '0.': IRI-95
    # '1.': FPT-2000
    'dreg': '0.',
    # probab:
    # '0.': Scotto-1997 no L
    # '1.': Scotto-1997 with L
    # '2.': IRI-95
    'probab': '0.',
    'nmf2' : '0.',
    'f2' : '0.'
}

def IRI(latitude, longitude):
    fileName = open('/home/sjy/Desktop/tests233.txt', 'a+')
    payload['latitude'] = latitude
    payload['longitude'] = longitude
    fileName.write('\n======= latitude: ' + str(latitude) + ', longitude: ' + str(longitude) + ' =======\n')
    r = requests.post(request_url, data=payload)
    fileName.write(r.text)
    fileName.close()
