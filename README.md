## Create and manage dashboards with the Guimaker mobile app
Guide: https://guimaker.app

## Project: Switch on/off a led attached to an Arduino Uno
Project description: https://guimaker.pro/demoprojects


## 1 Project setup
Download the project to your pc
Copy your database config to the firebase-config.json file
Edit the environment variables in dash.env
Use the 'scp' command to copy the project folder to the Raspberry Pi
Run the setup.sh file to complete the setup 

## 2 Copy the Firbase database config
- Log in to the Firebase console
- Go to Project Settings, then scroll down
- Copy the key-pairs to the the firebase-config.json 

setup.sh will add double quotes to the keys to make the file a valid json file

## 3 Edit dash.env 
Complete or edit the values for:
- EMAIL=
- PASSWORD=
- DASHBOARD_NAME=

- USB_PORT=ttyACM0
- LED_SWITCH_LABEL=Led
- FIREBASE_CONFIG=firebase-config.json

The Arduino should attached to the USB port ttyACM0 of the Raspberry Pi. 
You can run the command 'dmesg | grep' on the Raspberry Pi to be sure in case if you 
have more than on device attached to the Raspberry Pi

## 4 Copy the project folder to the raspberry Pi
Let's say:
- The destination folder on the Pi is /home/pi
- The Pi ip address is 10.0.0.30
- username is 'pi'
Run:  scp -r led pi@10.0.0.30:/home/pi

## 5 Run the setup.sh script to complete the setup
SSH to the raspberry then cd to your project folder and run:
bash setup.sh

The script will:
- Set the project name to the project folder name
- Set the project description
- Install the dependencies
- Add executable permissions to dash.js
- Add the project folder path to dash.env"
- Rename the following files to the project name
  - dash.js        > led.js
  - dash.env       > led.env
  - dash.service   > led.service

- Replace 'dash' with the project name in packge.json, package-lock.json
  - "name": "dash" 
  - "main": "dash.js"

- Wrap the firebase-config.json keys with double quotes 

- Configure the led.service by updating
  - project description
  - path2dah.js
  - dash-identifier
  - user-name
  - path2dash.env

- Move led.service to /etc/systemd/sysem
- Enable the led service to start at boot time
- Start the led service
- Check the led service status
 
## Troubleshoot the setup
Check the path and filenames are correctly spelled in:
  - led.env
  - led.service

  Keep in mind that Dashboard names created in the mobile app are case sensitive