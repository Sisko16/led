/***
 Switch a led on/off
 ***/
import {SerialPort} from 'serialport'

const usbPort = process.env.ARDUINO_USB_PORT;
const port = new SerialPort({path:'/dev/' + usbPort, baudRate:9600});

export const process_data = (data) => {
   
    const led_state = (data.val().payload) ? 'on' : 'off'
 
    port.write(led_state, (error) => {
        console.log (error)
        return
    });

    port.on('error', (error) => { 
        console.log (error)
        return
    });
}