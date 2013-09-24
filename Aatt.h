/*
	Aatt.h - Library for sending data to aatt server
	@author Patrick Hoolboom
	@date 9/24/2013
*/
#ifndef Aatt_h
#define Aatt_h

#include "Arduino.h"
#include "Ethernet.h"
#include "SPI.h"

class Aatt {
	
	public:
		Aatt();
		setSyncUrl(String url, int port);
		setAccount(string account,String key);
		setDevice(int device_id);
		setAct(String act);
		record(int endpoint, String value);
		check(int endpoint, int attribute);
		send();
	private:
		compile();
		String _url;
		String _port;
		String _account;
		String _key;
		String _device_id;
		String _act;
};

#endif