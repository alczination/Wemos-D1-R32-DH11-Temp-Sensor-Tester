<h2>DH11 Sensor with External Server Support</h2>
<h3>Wiring Diagram</h3>
<img src="wiring.webp"/>
<p>Connect DATA to Analog port 104</p>
<h2>Installation on Webserver</h2>
<h3>Install all necessary dependencies</h3>
<code>sudo apt update</code>
<p></p>
<code>sudo apt install python3-pip -y</code>
<p></p>
<code>pip3 install flask</code>
<h3>Allow port 5000</h3>
<code>sudo ufw allow 5000</code>
<h3>Run the script.py on Server</h3>
<code>python3 script.py</code>
<h2>Run on WEMOS</h2>
<h3>Change Wifi credentials</h3>
<code>const char* ssid = <span style="color=green">"YOUR_NETWORK_SSID"</span>;</code>
<p></p>
<code>const char* password = "YOUR_NETWORK_PASSWORD";</code>
<p></p>
<h3>Change Server IP</h3>
<code>const char* serverName = "http://YOUR_SERVER_IP:5000/sensor";</code>
