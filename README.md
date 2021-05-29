# crazy_bot_mqtt_eps8266
Whelled robot on Arduino and ESP8266 controlled by MQTT.

## settings for MQTT connection:

I use HiveMQ Broker to control the robot.
You can access the broker at:

### settings for HiveMQ connection:

Broker: broker.hivemq.com

TCP Port: 1883

Websocket Port: 8000

More information you can find at https://www.hivemq.com/public-mqtt-broker/

You can use web-client to test MQTT connection and control at http://www.hivemq.com/demos/websocket-client/.

### mqtt topics information:

For control commands used __crazyBot666/commands__ topic.

For debug messages from bot used __crazyBot666/debug__ topic.
