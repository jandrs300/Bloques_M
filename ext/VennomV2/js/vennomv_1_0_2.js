// vennom.js

(function(ext) {
    var device = null;
    var _rxBuf = [];

    // Sensor states:
    var ports = {
        Port1: 1,
        Port2: 2,
        Port3: 3,
        Port4: 4,
        Port5: 5,
        Port6: 6,
        Port7: 7,
        Port8: 8,
		M1:9,
		M2:10
    };
	var slots = {
		Slot1:1,
		Slot2:2
	};
	var switchStatus = {
		On:1,
		Off:0
	};
	var levels = {
		HIGH:1,
		LOW:0
	};
	var motorVal = {
		S1:2,
		S2:4,
		S3:7,
		S4:12
	};
	var axis = {
		'X-Axis':1,
		'Y-Axis':2,
		'Z-Axis':3
	};
	var tones ={"Si0":31,"Do1":33,"Re1":37,"Mi1":41,"Fa1":44,"Sol1":49,"LA1":55,"Si1":62,
			"Do2":65,"Re2":73,"Mi2":82,"Fa2":87,"Sol2":98,"LA2":110,"Si2":123,
			"Do3":131,"Re3":147,"Mi3":165,"Fa3":175,"Sol3":196,"LA3":220,"Si3":247,
			"Do4":262,"Re4":294,"Mi4":330,"Fa4":349,"Sol4":392,"LA4":440,"Si4":494,
			"Do5":523,"Re5":587,"Mi5":659,"Fa5":698,"Sol5":784,"LA5":880,"Si5":988,
			"Do6":1047,"Re6":1175,"Mi6":1319,"Fa6":1397,"Sol6":1568,"LA6":1760,"Si6":1976,
			"Do7":2093,"Re7":2349,"Mi7":2637,"Fa7":2794,"Sol7":3136,"LA7":3520,"Si7":3951,
			"Do8":4186,"Re8":4699};
	var beats = {"Half":500,"Quarter":250,"Eighth":125,"Whole":1000,"Double":2000,"Zero":0};
	var values = {};
	var indexs = [];
	var startTimer = 0;
	var versionIndex = 0xFA;
    ext.resetAll = function(){
    	device.send([0xff, 0x55, 2, 0, 4]);
    };
	ext.runArduino = function(){
		responseValue();
	};
	ext.runDigital = function(pin,level) {
        runPackage(30,pin,typeof level=="string"?levels[level]:new Number(level));
    };
	ext.runAnalog = function(pin, valu) {
	    runPackage(31,pin,valu);
	};
	ext.setupBoard = function(){
		ext.runDigital(7,levels["HIGH"]);
    }; 
	ext.runMotor = function(pin,valu){
		ext.runDigital(pin-1, valu >=0 ? levels["LOW"]:levels["HIGH"]);
		ext.runAnalog(pin, valu*-1);
	};
	ext.onLedArdui = function(level){
		unPackage(30,13,typeof level=="string"?levels[level]:new Number(level));
	};
	ext.onLed = function(color,level){
		unPackage(30,color,typeof level=="string"?levels[level]:new Number(level));
		//runPackage(32,color,typeof level=="string"?levels[level]:new Number(level));
	};
	ext.onRGBPwm = function(r,g,b) {
        runPackage(32,6,r);
        runPackage(32,5,g);
        runPackage(32,3,b);
    };
	ext.onBuzzer = function(level){
		unPackage(30,11,typeof level=="string"?levels[level]:new Number(level));
	};

	ext.onTone = function(tone,beat){
		runPackage(34,11,short2array(typeof tone=="number"?tone:tones[tone]),short2array(typeof beat=="number"?beat:beats[beat]));
	};
	ext.onMotorD = function(a,b){
		unPackage(30,2,a);
		unPackage(30,4,b);
	};
	ext.onMotorI = function(a,b){
		unPackage(30,7,a);
		unPackage(30,12,b);
	};
	ext.actMotor = function(a,b){
		runPackage(30,a,b);
	};
	ext.actMotorT = function(a,b,c){
		runPackage(30,a,b,c);
	};
	ext.onVennom = function(movimiento){
		runPackage(30,movimiento);
	};
	ext.giroVennom = function(grado,giro){
		runPackage(30,grado,giro);
	};
	ext.getUltrasonicVennom = function(nextID,trig,echo){
		var deviceId = 36;
		getPackage(nextID,deviceId,10,13);
	};
	ext.getInfrarrojo = function(nextID,pin) {
		var deviceId = 31;
		getPackage(nextID,deviceId,pin);
    };
    ext.runPwm = function(pin,pwm) {
        runPackage(32,pin,pwm);
    };
	ext.runTone = function(pin,tone,beat){
		runPackage(34,pin,short2array(typeof tone=="number"?tone:tones[tone]),short2array(typeof beat=="number"?beat:beats[beat]));
	};
	ext.runServoArduino = function(pin, angle){
		runPackage(33,pin,angle);
	};
	ext.resetTimer = function(){
		startTimer = new Date().getTime();
		responseValue();
	};
	ext.getDigital = function(nextID,pin){
		var deviceId = 30;
		getPackage(nextID,deviceId,pin);
	};
	ext.getAnalog = function(nextID,pin) {
		var deviceId = 31;
		getPackage(nextID,deviceId,pin);
    };
	ext.getPulse = function(nextID,pin,timeout) {
		var deviceId = 37;
		getPackage(nextID,deviceId,pin,short2array(timeout));
    };
	ext.getUltrasonicArduino = function(nextID,trig,echo){
		var deviceId = 36;
		getPackage(nextID,deviceId,trig,echo);
	};
	ext.getTimer = function(nextID){
		if(startTimer==0){
			startTimer = new Date().getTime();
		}
		responseValue(nextID,new Date().getTime()-startTimer);
	}

	function sendPackage(argList, type){
		var bytes = [0xff, 0x55, 0, 0, type];
		for(var i=0;i<argList.length;++i){
			var val = argList[i];
			if(val.constructor == "[class Array]"){
				bytes = bytes.concat(val);
			}else{
				bytes.push(val);
			}
		}
		bytes[2] = bytes.length - 3;
		device.send(bytes);
	}
	
	function runPackage(){
		sendPackage(arguments, 2);
	}
	function getPackage(){
		var nextID = arguments[0];
		Array.prototype.shift.call(arguments);
		sendPackage(arguments, 1);
	}

    var inputArray = [];
	var _isParseStart = false;
	var _isParseStartIndex = 0;
    function processData(bytes) {
		var len = bytes.length;
		if(_rxBuf.length>30){
			_rxBuf = [];
		}
		for(var index=0;index<bytes.length;index++){
			var c = bytes[index];
			_rxBuf.push(c);
			if(_rxBuf.length>=2){
				if(_rxBuf[_rxBuf.length-1]==0x55 && _rxBuf[_rxBuf.length-2]==0xff){
					_isParseStart = true;
					_isParseStartIndex = _rxBuf.length-2;
				}
				if(_rxBuf[_rxBuf.length-1]==0xa && _rxBuf[_rxBuf.length-2]==0xd&&_isParseStart){
					_isParseStart = false;
					
					var position = _isParseStartIndex+2;
					var extId = _rxBuf[position];
					position++;
					var type = _rxBuf[position];
					position++;
					//1 byte 2 float 3 short 4 len+string 5 double
					var value;
					switch(type){
						case 1:{
							value = _rxBuf[position];
							position++;
						}
							break;
						case 2:{
							value = readFloat(_rxBuf,position);
							position+=4;
							if(value<-255||value>1023){
								value = 0;
							}
						}
							break;
						case 3:{
							value = readInt(_rxBuf,position,2);
							position+=2;
						}
							break;
						case 4:{
							var l = _rxBuf[position];
							position++;
							value = readString(_rxBuf,position,l);
						}
							break;
						case 5:{
							value = readDouble(_rxBuf,position);
							position+=4;
						}
							break;
						case 6:
							value = readInt(_rxBuf,position,4);
							position+=4;
							break;
					}
					if(type<=6){
						responseValue(extId,value);
					}else{
						responseValue();
					}
					_rxBuf = [];
				}
			} 
		}
    }
	function readFloat(arr,position){
		var f= [arr[position],arr[position+1],arr[position+2],arr[position+3]];
		return parseFloat(f);
	}
	function readInt(arr,position,count){
		var result = 0;
		for(var i=0; i<count; ++i){
			result |= arr[position+i] << (i << 3);
		}
		return result;
	}
	function readDouble(arr,position){
		return readFloat(arr,position);
	}
	function readString(arr,position,len){
		var value = "";
		for(var ii=0;ii<len;ii++){
			value += String.fromCharCode(_rxBuf[ii+position]);
		}
		return value;
	}
    function appendBuffer( buffer1, buffer2 ) {
        return buffer1.concat( buffer2 );
    }

    // Extension API interactions
    var potentialDevices = [];
    ext._deviceConnected = function(dev) {
        potentialDevices.push(dev);

        if (!device) {
            tryNextDevice();
        }
    }

    function tryNextDevice() {
        // If potentialDevices is empty, device will be undefined.
        // That will get us back here next time a device is connected.
        device = potentialDevices.shift();
        if (device) {
            device.open({ stopBits: 0, bitRate: 115200, ctsFlowControl: 0 }, deviceOpened);
        }
    }

    var watchdog = null;
    function deviceOpened(dev) {
        if (!dev) {
            // Opening the port failed.
            tryNextDevice();
            return;
        }
        device.set_receive_handler('vennomv_1_0_2',processData);
    };

    ext._deviceRemoved = function(dev) {
        if(device != dev) return;
        device = null;
    };

    ext._shutdown = function() {
        if(device) device.close();
        device = null;
    };

    ext._getStatus = function() {
        if(!device) return {status: 1, msg: 'Vennom disconnected'};
        if(watchdog) return {status: 1, msg: 'Probing for Vennom'};
        return {status: 2, msg: 'Vennom connected'};
    }

    var descriptor = {};
	ScratchExtensions.register('vennomv_1_0_2', descriptor, ext, {type: 'serial'});
})({});
