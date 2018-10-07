import serial
import time
import requests
import json
serial_port= '/dev/ttyACM0'
baud_rate = 9600 #In arduino, Serial.begin(baud_rate)
write_to_file_path = "output.txt"

output_file = open(write_to_file_path, "w+");
ser = serial.Serial(serial_port, baud_rate)
c=1
data = json.loads("""{"light": "","temperature": ""}""")
headers ={'content-type':'application/json'}
while True:
    line = ser.readline();
    line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    if "light" in line:
       data['light']=str(line.rstrip()).split('=')[1]
    elif "temperature" in line:
       data['temperature']=str(line.rstrip()).split('=')[1]
    
    if c % 2 == 0:
       response = requests.post('http://172.17.112.62:3001/sensorsData', json.dumps(data) ,headers=headers)
       print(json.dumps(data))
    c+=1
    print(line);
    output_file.write(line);
