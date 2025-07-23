# 🏥 Hospital Management System in C++ (OOP-Based)

This is a console-based Hospital Management System developed using **C++**, demonstrating **all major Object-Oriented Programming (OOP)** principles. The system simulates hospital workflows such as booking appointments, managing users, and storing patient records.

---

## 📌 Project Overview

### 🎯 Roles Supported:
- **Patient** – Book/view appointments, access medical history.
- **Doctor** – Diagnose patients, view appointments.
- **Admin** – Manage patients and doctors, access data using friend functions.

### 🔧 Key Features:
- User Authentication (Basic)
- Appointment Booking
- Viewing and Storing Medical Records
- Diagnosis Handling
- Role-based Menus
- Persistent Data using File I/O

---

## 🧠 C++ OOP Concepts Used

| Concept         | Applied In                                   |
|----------------|-----------------------------------------------|
| **Classes & Objects** | `User`, `Patient`, `Doctor`, `Admin` |
| **Inheritance**       | `Patient` and `Doctor` inherit `User`  |
| **Polymorphism**      | Virtual functions like `showMenu()`    |
| **Encapsulation**     | Private patient info + public accessors |
| **Abstraction**       | Defined interfaces, hides details       |
| **Friend Functions**  | Admin accessing patient/doctor data     |
| **File I/O**          | Store medical records and appointments  |

---

## 📂 Project Structure

📁 HospitalManagementSystem/
│
├── main.cpp                 # Main driver file  
├── User.h                  # Abstract base class  
├── Patient.h / Patient.cpp # Patient role logic  
├── Doctor.h / Doctor.cpp   # Doctor role logic  
├── Admin.h / Admin.cpp     # Admin functions  
├── Appointment.h / .cpp    # (Optional) Appointment handling  
├── records/                # Stores patient history as text files  
└── README.md               # This documentation  

---

## ⚙️ How to Compile and Run

### 💻 Windows PowerShell or CMD:
```bash
g++ *.cpp -o main
.\main
```

### 🐧 Linux / macOS:
```bash
g++ *.cpp -o main
./main
```
