/*
	Aatt.cpp - Library for sending data to aatt server
	@author Patrick Hoolboom
	@date 9/24/2013
*/

#include "Arduino.h"
#include "Ethernet.h"
#include "SPI.h"
#include "Aatt.h"

Aatt::Aatt() {

}

void Aatt::setSyncUrl(String url, int port) {
	_url = url;
	_port = port;
}

void Aatt::setAccount(String account, String key) {
	_account = account;
	_key = key;
}

void Aatt::setDevice(int device_id) {
	_device_id = device_id;
}

void Aatt::setAct(String act) {
	_act = act;
}

void Aatt::record(int endpoint, String value) {

}

void Aatt::check(int endpoint, int attribute) {

}

void Aatt::compile() {

}

String Aatt::send(){

}