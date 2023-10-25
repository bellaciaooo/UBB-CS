from Lab_studenti.service.lab_service import *
from Lab_studenti.service.student_service import *

class Console:
    def __init__(self, lab_service : LabService, student_service : StudentService):
        self.__lab_service = lab_service
        self.__student_service = student_service

    def vizualizareStudenti(self):
        """
            Se afiseaza lista de studenti curenta.
        """
        students = self.__student_service.getStudents()
        if len(students) == 0:
            print("Nu exista studenti in lista!")
        else:
            for student in students:
                print(student)

    def searchStudentById(self):
        """
            Se cauta studentul in functie de id-ul introdus de la tastatura.
        """
        id_student = input("Introduceti id-ul studentului cautat: ")
        id_student = int(id_student)
        gasit = self.__student_service.searchStudentById(id_student)
        print(gasit)

    def asignareLab(self):
        """
            Se asigneaza un nou laborator unui student in functie de id - ul studentului si nr de laborator.
        """
        id_student = input("Id-ul studentului este: ")
        nr_lab = input("Nr-ul laboratorului este: ")
        nr_problema = input("Nr-ul problemei este: ")
        id_student = int(id_student)
        nr_lab = int(nr_lab)
        self.__lab_service.addLab(id_student, nr_lab, nr_problema)

    def vizualizareLabs(self):
        """
           Se afiseaza laboaratoarele in functie de id-ul studentului introdus.
        """
        id_student = input("Introduceti id-ului studentului: ")
        id_student = int(id_student)
        labs = self.__lab_service.getLabsByStudentId(id_student)
        if len(labs) == 0:
            print("Studentul introdus nu are niciun laborator asignat.")
        else:
            for lab in labs:
                print(lab)

    def studentsAndLabsForLabNr(self):
        lab_nr = input("Introduceti numarul laboratorului dorit: ")
        lab_nr = int(lab_nr)
        students = self.__student_service.getStudents()
        labs = self.__lab_service.LabsByLabNr(lab_nr)
        if len(labs) == 0:
            print("Nu exista studenti asignati la laboratorul introdus.")
        else:
            for lab in labs:
                for student in students:
                    if lab.getId_student() == student.getId_student():
                        print('Id student: '+ str(student.getId_student())+ ', Nume student: '+student.getNume() + ', Numar problema: ' + lab.getNr_problema() + ' la laboratorul numarul: '+ str(lab.getNr_lab()))


    def menu(self):
        print("0. Iesirea din aplicatie.")
        print("1. Vizualizare lista studenti.")
        print("2. Cautare student dupa id. ")
        print("3. Asignare laborator la un elev.")
        print("4. Vizualizare toate laboratoare de la un student.")
        print("5. Vizualizare studenți si laboratoare asignate pentru un laborator dat. ")

    def run(self):
        self.menu()
        dictionary_of_commands = {
            "1" : self.vizualizareStudenti,
            "2" : self.searchStudentById,
            "3" : self.asignareLab,
            "4" : self.vizualizareLabs,
            "5" : self.studentsAndLabsForLabNr
        }
        while True:
            command = input("Introduceti optiunea dorita: ")
            if command in dictionary_of_commands:
                try:
                    dictionary_of_commands[command]()
                except ServiceException as ex:
                    print(ex)
                except RepoException as ex:
                    print(ex)
                except ValidatorException as ex:
                    print(ex)
                except ValueError:
                    print("Valoarea introdusa trebuie sa fie de tip integer!")
                self.menu()
            elif command == "0":
                break
            else:
                print("Optiunea aleasa nu exista! ")