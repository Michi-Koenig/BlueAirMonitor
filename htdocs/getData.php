<?php
/*
$typOfTime = $_GET['typOfTime'];
$timeperiod = $_GET['timeperiod'];
$projekt = $_GET['projekt'];
$room = $_GET['room'];
$divices = $_GET['devices'];
*/
// Erstelle die Vriabeln
$project = "Holderbaum";
$room = "Schlafen";
$devices = 2;

// Erstelle die Arrays
$arrayTime = array(1, 2, 3, 4, 5);

$arrayTemp1 = array("19", "20", "20", "21", "19");
$arrayHum1 = array("50", "51", "52", "51", "51");
$arrayPres1 = array("965", "965", "963", "960", "961");
$arrayCo21 = array("450", "455", "454", "455", "455");

$arrayTemp2 = array("23", "22", "21", "21", "22");
$arrayHum2 = array("45", "47", "47", "48", "49");
$arrayPres2 = array("954", "956", "957", "958", "955");
$arrayCo22 = array("490", "485", "480", "480", "478");
$arrayData =array($arrayTemp1, $arrayHum1, $arrayPres1, $arrayCo21, $arrayTemp2, $arrayHum2, $arrayPres2, $arrayCo22);

// Erstelle das JSON Objekt
$jsonObject = array(
    "project" => $project,
    "room" => $room,
    "devices" => $devices,
    "time" => $arrayTime,
    "data" => $arrayData
);

// Gib das JSON Objekt aus
echo json_encode($jsonObject, JSON_PRETTY_PRINT);

?>
