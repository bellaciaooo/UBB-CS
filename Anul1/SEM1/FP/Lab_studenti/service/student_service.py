from Lab_studenti.repository.student_repo import *

class StudentService:
    def __init__(self, student_repo : StudentRepoFile):
        self.__student_repo = student_repo

    def getStudents(self):
        return self.__student_repo.getStudents()

    def searchStudentById(self, id_student):
        return self.__student_repo.searchStudentById(id_student)

