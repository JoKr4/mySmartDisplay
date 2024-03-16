#include "websocket_client.h"

#include <SocketIOclient.h>
#include <WebSocketsClient.h>

#include "ui_custom.h"

static WebSocketsClient webSocket;

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
	switch(type) {
		case WStype_DISCONNECTED:
            ui_writeLog("[WSc] Disconnected");
			break;
		case WStype_CONNECTED:
			ui_writeLog("[WSc] Connected");
			webSocket.sendTXT("Connected");
			break;
		case WStype_TEXT:
			ui_writeLog("[WSc] get text");
			// webSocket.sendTXT("message here");
			break;
		case WStype_BIN:
			ui_writeLog("[WSc] get binary length");
			//hexdump(payload, length);
			// webSocket.sendBIN(payload, length);
			break;
		case WStype_ERROR:			
		case WStype_FRAGMENT_TEXT_START:
		case WStype_FRAGMENT_BIN_START:
		case WStype_FRAGMENT:
		case WStype_FRAGMENT_FIN:
			break;
	}
}

void init_websocket_client() {
    webSocket.begin("192.168.178.69", 8090, "/ws");
    webSocket.onEvent(webSocketEvent);
}

void loop_websocket_client() {
    webSocket.loop();
}