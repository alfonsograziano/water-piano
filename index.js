const { SerialPort } = require("serialport");
const { ReadlineParser } = require("@serialport/parser-readline");
const robot = require("robotjs");
const portName = "/dev/cu.usbmodem11301";

const serialToKeyMap = {
  1: "a", // C
  2: "w",
  3: "s",
  4: "e",
  5: "d",
  6: "f",
  7: "t",
  8: "g",
  9: "y",
  10: "h",
  11: "u",
  12: "j",
  13: "k",
  14: "o",
  15: "l",
  16: "p",
  17: ";",
  18: "'",
  19: "z", // - octave
  20: "x", // + octave
};

// Replace with your serial port name
const port = new SerialPort({
  path: portName,
  baudRate: 9600,
});
const parser = port.pipe(new ReadlineParser({ delimiter: "\r\n" }));

// Open the serial port
port.on("open", function () {
  console.log("Serial Port Opened");
});

// Read the data from the serial port
parser.on("data", function (data) {
  console.log("Received data: " + data);
  const [action, noteKey] = data.split(":");
  const note = serialToKeyMap[noteKey];

  console.log(action, noteKey, note);
  robot.keyToggle(note, action === "u" ? "up" : "down");
});

// Handle serial port errors
port.on("error", function (err) {
  console.error("Error: ", err.message);
});
