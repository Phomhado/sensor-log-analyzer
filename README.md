# Sensor Log Analyzer

The first project of my personal **Project Northbound**.

*"Mot nord. Ett steg om gangen!"*

---

## Description

Sensor Log Analyzer is a command-line application written in Modern C++.

Its purpose is to read vessel sensor logs, validate user input, extract telemetry data, detect malformed entries, and eventually produce useful summaries for maritime monitoring systems.

This project is part of my learning journey toward becoming a Software Engineer focused on systems programming and the Norwegian maritime industry.

---

## Goals

- Learn Modern C++
- Practice file handling
- Practice string parsing
- Learn command-line applications
- Learn CMake
- Build production-quality code

---

## Features

Current capabilities:

- Read log files from the command line
- Validate command-line arguments
- Display usage instructions when arguments are missing
- Open user-specified log files
- Detect file opening errors
- Read log files line by line
- Extract timestamps
- Extract RPM values
- Extract temperature values
- Generic parsing function for future sensor types

---

## Current Status

**Version:** 0.2

Current architecture:

- Command-line interface (CLI)
- Generic value extraction function
- Timestamp wrapper
- File validation
- Error handling
- Modular helper functions

---

## Example

Input:

```text
2026-07-30T20:31:11 RPM=2450 TEMP=78.3
```

Output:

```text
Timestamp: 2026-07-30T20:31:11
RPM: 2450
TEMP: 78.3
```

---

## Project Structure

```text
SensorLogAnalyzer/
├── src/
│   ├── main.cpp
│   └── sample.log
├── CMakeLists.txt
└── README.md
```

---

## Roadmap

### Version 0.2
- Command-line arguments
- File validation
- Generic parser
- Timestamp extraction

### Next

- SensorReading model
- Store readings instead of printing immediately
- Detect malformed log entries
- Parse numeric values (`stoi` / `stod`)
- Calculate statistics
- Export summaries

---

## Project Northbound

This project is one milestone in **Project Northbound**, a long-term journey toward software engineering opportunities in Norway through consistent practice, real-world projects, and continuous learning.

*"Mot nord. Ett steg om gangen."*