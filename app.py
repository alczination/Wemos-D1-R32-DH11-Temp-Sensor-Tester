from flask import Flask, request, jsonify
app = Flask(__name__)

@app.route('/sensor', methods=['POST'])
def receive_data():
	data = request.json
	temp = data.get('temperature')
	humid = data.get('humidity')
	
	print(f"Temp: {temp}C, Humidity: {humid}%")
	return jsonify({"status:": "success"}), 200

if __name__ == '__main__':
	app.run(host='0.0.0.0', port=5000)