from Lab_studenti.repository.lab_repo import *
from Lab_studenti.repository.student_repo import *
from Lab_studenti.validators.validators import *

class LabService:
    def __init__(self, lab_repo : LabRepoFile, lab_vali : LabValidator, student_repo : StudentRepoFile):
        self.__lab_repo = lab_repo
        self.__lab_vali = lab_vali
        self.__student_repo = student_repo

    def getLabs(self):
        return self.__lab_repo.getLabs()

    def addLab(self, id_student, nr_lab, nr_problema):
        newLab = Lab(id_student, nr_lab, nr_problema)
        try:
            self.__lab_vali.validate(newLab)
            try:
                self.__lab_repo.addLab(newLab)
            except RepoException as ex:
                raise ServiceException(ex)
        except ValidatorException as ex:
            raise ServiceException(ex)

    def getLabsByStudentId(self, id_student):
        labs = self.__lab_repo.getLabs()
        labs_student = []
        try:
            student = self.__student_repo.searchStudentById(id_student)
            for lab in labs:
                if lab.getId_student() == student.getId_student():
                    labs_student.append(lab)
            return labs_student
        except RepoException as ex:
            raise ServiceException(ex)

    def LabsByLabNr(self, lab_nr):
        labs = self.__lab_repo.getLabs()
        labs_for_lab_nr = []
        for lab in labs:
            if lab.getNr_lab() == lab_nr:
                labs_for_lab_nr.append(lab)
        return labs_for_lab_nr