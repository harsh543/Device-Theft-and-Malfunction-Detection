import geocoder
import time
import requests
import json


filename = "testfile.txt"
open(filename, 'w').close()
file = open(filename,"a")

count = 0
while True:
	pos_list = []	
	if(count == 0):
		headers = {'content-type': 'application/json'}
		data = {"newLatitude":"41.8698","newLongitude":"-95.6496","oldLatitude":"41.862977","oldLongitude":"-95.53831799","deviceId":"1"}
		#print(type(data))
		json_data = json.dumps(data)		
		#data = json.loads(""" {"newLatitude":"41.8698","newLongitude":"-95.6496","oldLatitude":"41.662977","oldLongitude":"-91.53831799","deviceId":"2"}""")
		response = requests.post('http://172.17.112.62:3001/geoData',json_data, headers = headers )
		#print(json_data)
		file.write('41.8698,'+'-95.6496')
		count = 1
	else:
		g = geocoder.ip('me')
		pos_list = g.latlng
	lat = ''     
	for c,k in enumerate(pos_list):
		print(c)
		if (c == 0):
			lat = str(k)	
			#response = requests.post('http://172.17.112.62:3001/geoData', data = {'newLatitude':st})
			print(response)
			file.write(str(k)+',')
		else:
			st = str(k)
			data = {"newLatitude":lat,"newLongitude":st,"oldLatitude":"41.662977","oldLongitude":"-91.53831799","deviceId":"1"}
			json_data = json.dumps(data)			
			#data = json.loads(""" {"newLatitude":"","newLongitude":"","oldLatitude":"41.662977","oldLongitude":"-91.53831799","deviceId":"2"}""")
			#data['newLatitude'] = lat
			#data['newLongitude']= st
			response = requests.post('http://172.17.112.62:3001/geoData', json_data)
			print(response)
			file.write(st+',41.662977,'+'-91.53831799')
		      
	file.write('\n') 
	file.close    
	time.sleep(10)
