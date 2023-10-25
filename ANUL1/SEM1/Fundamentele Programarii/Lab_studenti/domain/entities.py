from dataclasses import dataclass

@dataclass
class Student:
    def __init__(self, id_student, nume):
        self.__id_student = id_student
        self.__nume = nume

    def getId_student(self):
        return self.__id_student

    def getNume(self):
        return self.__nume

    def setId_student(self, value):
        self.__id_student = value

    def setNume(self, value):
        self.__nume = value

    def __eq__(self, other):
        return self.getId_student() == other.getId_student()

    def __str__(self):
        return f"ID student: {self.__id_student}, Nume: {self.__nume} "


class Lab:
    def __init__(self, id_student, nr_lab, nr_problema):
        self.__id_student = id_student
        self.__nr_lab = nr_lab
        self.__nr_problema = nr_problema

    def getId_student(self):
        return self.__id_student

    def getNr_lab(self):
        return self.__nr_lab

    def getNr_problema(self):
        return self.__nr_problema

    def setId_student(self, value):
        self.__id_student = value

    def setNr_lab(self, value):
        self.__nr_lab = value

    def setNr_problema(self, value):
        self.__nr_problema = value

    def __eq__(self, other):
        return self.getId_student() == other.getId_student() and self.getNr_lab() == other.getNr_lab()

    def __str__(self):
        return f"ID student: {self.__id_student}, Numar laborator: {self.__nr_lab}, Numar problema: {self.__nr_problema} "
