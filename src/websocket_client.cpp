#include "websocket_client.h"

#include <SocketIOclient.h>
#include <WebSocketsClient.h>

#include "ui_custom.h"
#include "messaging.h"

static WebSocketsClient webSocket;


void hexdump(const void *mem, uint32_t len, uint8_t cols = 16) {
	const uint8_t* src = (const uint8_t*) mem;
	char buffer[64];
    sprintf(buffer, "\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
	for(uint32_t i = 0; i < len; i++) {
		if(i % cols == 0) {
			sprintf(buffer, "\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
		}
		sprintf(buffer, "%02X ", *src);
		src++;
	}
	sprintf(buffer, "\n");

    ui_writeLog(std::string(buffer, 64));
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
	switch(type) {
		case WStype_DISCONNECTED:
            ui_writeLog("[WSc] Disconnected");
			break;
		case WStype_CONNECTED:
			ui_writeLog("[WSc] Connected");
			//webSocket.sendTXT("Connected");
			break;
		case WStype_TEXT:
			ui_writeLog("[WSc] rx text");
			// webSocket.sendTXT("message here");
			break;
		case WStype_BIN:
			ui_writeLog("[WSc] rx binary");
			//msg_receive(payload, length);
			hexdump(payload, length);
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
    webSocket.begin("192.168.178.69", 8090, "/subscribe");
    webSocket.onEvent(webSocketEvent);
	webSocket.setReconnectInterval(5000);
	webSocket.setExtraHeaders(); // remove "Origin: file://" header because it breaks the connection with "nhooyr.io/websocket"
}

void loop_websocket_client() {
    webSocket.loop();
}
