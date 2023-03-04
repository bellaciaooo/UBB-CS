from Lab_studenti.exceptions.exceptions import *
from Lab_studenti.domain.entities import *

class StudentRepoFile:
    def __init__(self, fileName):
        self.__filename = fileName

    def __load_from_file(self):
        try:
            f = open(self.__filename, 'r')
        except IOError:
            raise CorruptedFileException("File Error: Nu exista fisier cu numele dat! ")

        students = []
        lines = f.readlines()
        for line in lines:
            id_student, nume = [token.strip() for token in line.split(',')]
            student = Student(int(id_student), nume)
            students.append(student)

        f.close()
        return students

    def searchStudentById(self, id_student):
        """
            Cauta in lista studentul avand id-ul = id_student
            Returneaza * studentul, daca acesta exista in lista
                       * ridica exceptie, in caz contrar
        """
        all_students = self.__load_from_file()
        for student in all_students:
            if student.getId_student() == id_student:
                return student
        raise RepoException("Nu exista studentul cu id-ul dat!")

    def getStudents(self):
        return  self.__load_from_file()
