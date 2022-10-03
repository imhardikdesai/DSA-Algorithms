// Solution for https://www.hackerrank.com/challenges/one-month-preparation-kit-time-conversion/problem?h_r=internal-search
"use strict";

const fs = require("fs");

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on("end", function () {
  inputString = inputString.split("\n");

  main();
});

function readLine() {
  return inputString[currentLine++];
}

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

function timeConversion(s) {
  // Write your code here
  try {
    let takeString = "";
    takeString = s;
    console.log(takeString);
    let ifAM = 0;
    ifAM = takeString.search(/AM/);
    console.log("if value:", ifAM);
    if (ifAM > 0) {
      console.log("The input is AM");
      let newTime = takeString.replace("AM", "");
      console.log("after replace: ", newTime);
      let hours = parseInt(newTime.substring(0, 2));
      let minute = parseInt(newTime.substring(3, 5));
      let second = parseInt(newTime.substring(6, 9));
      console.log("hours: ", hours);
      let realMinute = minute.toString();
      if (realMinute.length == 1) {
        let tempMinute = realMinute;
        realMinute = "0" + tempMinute;
      }
      let realSecond = second.toString();
      if (realSecond.length == 1) {
        let tempSecond = realSecond;
        realSecond = "0" + tempSecond;
      }
      console.log("minute: ", realMinute);
      console.log("second: ", realSecond);
      let init12 = hours;
      if (init12 >= 12) {
        init12 = init12 - 12;
      }
      let realHours = init12.toString();
      if (realHours.length == 1) {
        let tempHours = realHours;
        realHours = "0" + tempHours;
      }
      let initString = init12.toString();
      let finalVar = realHours + ":" + realMinute + ":" + realSecond;
      console.log(finalVar);
      return finalVar;
    } else {
      console.log("The input is PM");
      let newTime = takeString.replace("PM", "");
      console.log("after replace: ", newTime);
      let hours = parseInt(newTime.substring(0, 2));
      let minute = parseInt(newTime.substring(3, 5));
      let second = parseInt(newTime.substring(6, 9));
      let realMinute = minute.toString();
      if (realMinute.length == 1) {
        let tempMinute = realMinute;
        realMinute = "0" + tempMinute;
      }
      let realSecond = second.toString();
      if (realSecond.length == 1) {
        let tempSecond = realSecond;
        realSecond = "0" + tempSecond;
      }
      console.log("minute: ", realMinute);
      console.log("second: ", realSecond);
      let init12 = hours + 12;
      if (init12 >= 24) {
        init12 = init12 - 12;
      }
      let initString = init12.toString();
      let finalVar = initString + ":" + realMinute + ":" + realSecond;
      console.log(finalVar);
      return finalVar;
    }
  } catch (e) {
    console.log(e);
  }
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const s = readLine();

    const result = timeConversion(s);

    ws.write(result + '\n');

    ws.end();
}
