"""
    Simple python client websocket connection. 

    Use this script to verify the websocket created from IRC module. Check 
    on the controller logs to see if the client is recognized. 

"""

import socket

HOST = "192.168.0.102"
PORT = 21  # Replace with the correct port

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b"Hello Motion Server")
    data = s.recv(1024)

print(f"Received: {data.decode()}")
