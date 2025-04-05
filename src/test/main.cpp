#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const double PI = 3.14159;

// --- Conversion Functions ---
double feetToMeters(double feet) { return feet * 0.3048; }
double metersToFeet(double meters) { return meters / 0.3048; }
double milesToKilometers(double miles) { return miles * 1.60934; }
double kilometersToMiles(double kilometers) { return kilometers / 1.60934; }

double litersToCubicMeters(double liters) { return liters / 1000.0; }
double cubicMetersToLiters(double cubicMeters) { return cubicMeters * 1000.0; }
double gallonsToLiters(double gallons) { return gallons * 3.78541; }
double litersToGallons(double liters) { return liters / 3.78541; }

double kilogramsToPounds(double kilograms) { return kilograms * 2.20462; }
double poundsToKilograms(double pounds) { return pounds / 2.20462; }
double gramsToKilograms(double grams) { return grams / 1000.0; }
double kilogramsToGrams(double kilograms) { return kilograms * 1000.0; }

double celsiusToFahrenheit(double celsius) { return (celsius * 9.0 / 5.0) + 32.0; }
double fahrenheitToCelsius(double fahrenheit) { return (fahrenheit - 32.0) * 5.0 / 9.0; }
double celsiusToKelvin(double celsius) { return celsius + 273.15; }
double kelvinToCelsius(double kelvin) { return kelvin - 273.15; }
double fahrenheitToKelvin(double fahrenheit) { return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15; }
double kelvinToFahrenheit(double kelvin) { return (kelvin - 273.15) * 9.0 / 5.0 + 32.0; }

double joulesToKilojoules(double joules) { return joules / 1000.0; }
double kilojoulesToJoules(double kilojoules) { return kilojoules * 1000.0; }

double squareMetersToSquareFeet(double squareMeters) { return squareMeters * 10.7639; }
double squareFeetToSquareMeters(double squareFeet) { return squareFeet / 10.7639; }
double hectaresToSquareKilometers(double hectares) { return hectares / 100.0; }
double squareKilometersToHectares(double squareKilometers) { return squareKilometers * 100.0; }

double kmhToMps(double kmh) { return kmh * 1000.0 / 3600.0; }
double mpsToKmh(double mps) { return mps * 3600.0 / 1000.0; }
double mphToKmh(double mph) { return mph * 1.60934; }
double kmhToMph(double kmh) { return kmh / 1.60934; }

double secondsToMinutes(double seconds) { return seconds / 60.0; }
double minutesToSeconds(double minutes) { return minutes * 60.0; }
double minutesToHours(double minutes) { return minutes / 60.0; }
double hoursToMinutes(double hours) { return hours * 60.0; }

double wattsToKilowatts(double watts) { return watts / 1000.0; }
double kilowattsToWatts(double kilowatts) { return kilowatts * 1000.0; }

double pascalsToKilopascals(double pascals) { return pascals / 1000.0; }
double kilopascalsToPascals(double kilopascals) { return kilopascals * 1000.0; }
double atmToKpa(double atm) { return atm * 101.325; }
double kpaToAtm(double kpa) { return kpa / 101.325; }

double degreesToRadians(double degrees) { return degrees * PI / 180.0; }
double radiansToDegrees(double radians) { return radians * 180.0 / PI; }

void displayAvailableUnits() {
    cout << "Available unit types and units of measurement:\n";
    cout << "Length: feet, meters, miles, kilometers\n";
    cout << "Volume: liters, cubic meters, gallons\n";
    cout << "Weight: kilograms, pounds, grams\n";
    cout << "Mass: kilograms, pounds, grams\n";
    cout << "Temperature: celsius, fahrenheit, kelvin\n";
    cout << "Energy: joules, kilojoules\n";
    cout << "Area: square meters, square feet, hectares, square kilometers\n";
    cout << "Speed: km/h, m/s, mph\n";
    cout << "Time: seconds, minutes, hours\n";
    cout << "Power: watts, kilowatts\n";
    cout << "Pressure: pascals, kilopascals, atmospheres\n";
    cout << "Angle: degrees, radians\n";
    cout << endl;
}

int main() {
    displayAvailableUnits();

    string unitType;
    string inputUnit;
    string outputUnit;
    double value;

    cout << "Enter the unit type (e.g., Length, Speed): ";
    getline(cin >> ws, unitType);

    cout << "Enter the input unit: ";
    getline(cin >> ws, inputUnit);

    cout << "Enter the output unit: ";
    getline(cin >> ws, outputUnit);

    cout << "Enter the value to convert: ";
    cin >> value;
    if (cin.fail()) {
        cout << "Invalid input value.\n";
        return 1;
    }

    double result;

    if (unitType == "Length") {
        if (inputUnit == "feet" && outputUnit == "meters") {
            result = feetToMeters(value);
        }
        else if (inputUnit == "meters" && outputUnit == "feet") {
            result = metersToFeet(value);
        }
        else if (inputUnit == "miles" && outputUnit == "kilometers") {
            result = milesToKilometers(value);
        }
        else if (inputUnit == "kilometers" && outputUnit == "miles") {
            result = kilometersToMiles(value);
        }
        else {
            cout << "Invalid length conversion.\n";
            return 1;
        }
    }
    else if (unitType == "Volume") {
        if (inputUnit == "liters" && outputUnit == "cubic meters") {
            result = litersToCubicMeters(value);
        }
        else if (inputUnit == "cubic meters" && outputUnit == "liters") {
            result = cubicMetersToLiters(value);
        }
        else if (inputUnit == "gallons" && outputUnit == "liters") {
            result = gallonsToLiters(value);
        }
        else if (inputUnit == "liters" && outputUnit == "gallons") {
            result = litersToGallons(value);
        }
        else {
            cout << "Invalid volume conversion.\n";
            return 1;
        }
    }
    else if (unitType == "Weight" || unitType == "Mass") {
        if (inputUnit == "kilograms" && outputUnit == "pounds") {
            result = kilogramsToPounds(value);
        }
        else if (inputUnit == "pounds" && outputUnit == "kilograms") {
            result = poundsToKilograms(value);
        }
        else if (inputUnit == "grams" && outputUnit == "kilograms") {
            result = gramsToKilograms(value);
        }
        else if (inputUnit == "kilograms" && outputUnit == "grams") {
            result = kilogramsToGrams(value);
        }
        else {
            cout << "Invalid weight/mass conversion.\n";
            return 1;
        }
    }
    else if (unitType == "Temperature") {
        if (inputUnit == "celsius" && outputUnit == "fahrenheit") {
            result = celsiusToFahrenheit(value);
        }
        else if (inputUnit == "fahrenheit" && outputUnit == "celsius") {
            result = fahrenheitToCelsius(value);
        }
        else if (inputUnit == "celsius" && outputUnit == "kelvin") {
            result = celsiusToKelvin(value);
        }
        else if (inputUnit == "kelvin" && outputUnit == "celsius") {
            result = kelvinToCelsius(value);
        }
        else if (inputUnit == "fahrenheit" && outputUnit == "kelvin") {
            result = fahrenheitToKelvin(value);
        }
        else if (inputUnit == "kelvin" && outputUnit == "fahrenheit") {
            result = kelvinToFahrenheit(value);
        }
        else {
            cout << "Invalid temperature conversion.\n";
            return 1;
        }
    }
    else if (unitType == "Energy") {
        if (inputUnit == "joules" && outputUnit == "kilojoules") {
            result = joulesToKilojoules(value);
        }
        else if (inputUnit == "kilojoules" && outputUnit == "joules") {
            result = kilojoulesToJoules(value);
        }
        else {
            cout << "Invalid energy conversion.\n";
            return 1;
        }
    }
    else if (unitType == "Area") {
        if (inputUnit == "square meters" && outputUnit == "square feet") {
            result = squareMetersToSquareFeet(value);
        }
        else if (inputUnit == "square feet" && outputUnit == "square meters") {
            result = squareFeetToSquareMeters(value);
        }
        else if (inputUnit == "hectares" && outputUnit == "square kilometers") {
            result = hectaresToSquareKilometers(value);
        }
        else if (inputUnit == "square kilometers" && outputUnit == "hectares") {
            result = squareKilometersToHectares(value);
        }
        else {
            cout << "Invalid area conversion.\n";
            return 1;
        }
    }
    else if (unitType == "Speed") {
        if (inputUnit == "km/h" && outputUnit == "m/s") {
            result = kmhToMps(value);
        }
        else if (inputUnit == "m/s" && outputUnit == "km/h") {
            result = mpsToKmh(value);
        }
        else if (inputUnit == "mph" && outputUnit == "km/h") {
            result = mphToKmh(value);
        }
        else if (inputUnit == "km/h" && outputUnit == "mph") {
            result = kmhToMph(value);
        }
        else {
            cout << "Invalid speed conversion.\n";
            return 1;
        }
    }
    else if (unitType == "Time") {
        if (inputUnit == "seconds" && outputUnit == "minutes") {
            result = secondsToMinutes(value);
        }
        else if (inputUnit == "minutes" && outputUnit == "seconds") {
            result = minutesToSeconds(value);
        }
        else if (inputUnit == "minutes" && outputUnit == "hours") {
            result = minutesToHours(value);
        }
        else if (inputUnit == "hours" && outputUnit == "minutes") {
            result = hoursToMinutes(value);
        }
        else {
            cout << "Invalid time conversion.\n";
            return 1;
        }
    }
    else if (unitType == "Power") {
        if (inputUnit == "watts" && outputUnit == "kilowatts") {
            result = wattsToKilowatts(value);
        }
        else if (inputUnit == "kilowatts" && outputUnit == "watts") {
            result = kilowattsToWatts(value);
        }
        else {
            cout << "Invalid power conversion.\n";
            return 1;
        }
    }
    else if (unitType == "Pressure") {
        if (inputUnit == "pascals" && outputUnit == "kilopascals") {
            result = pascalsToKilopascals(value);
        }
        else if (inputUnit == "kilopascals" && outputUnit == "pascals") {
            result = kilopascalsToPascals(value);
        }
        else if (inputUnit == "atmospheres" && outputUnit == "kilopascals") {
            result = atmToKpa(value);
        }
        else if (inputUnit == "kilopascals" && outputUnit == "atmospheres") {
            result = kpaToAtm(value);
        }
        else {
            cout << "Invalid pressure conversion.\n";
            return 1;
        }
    }
    else if (unitType == "Angle") {
        if (inputUnit == "degrees" && outputUnit == "radians") {
            result = degreesToRadians(value);
        }
        else if (inputUnit == "radians" && outputUnit == "degrees") {
            result = radiansToDegrees(value);
        }
        else {
            cout << "Invalid angle conversion.\n";
            return 1;
        }
    }
    else {
        cout << "Unknown unit type: " << unitType << endl;
        return 1;
    }

    cout << value << " " << inputUnit << " = " << result << " " << outputUnit << endl;

    return 0;
}
