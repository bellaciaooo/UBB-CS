from Lab_studenti.exceptions.exceptions import *
from Lab_studenti.domain.entities import *

class LabRepoFile:
    def __init__(self, fileName):
        self.__fileName = fileName

    def __load_from_file(self):
        try:
            f = open(self.__fileName, 'r')
        except IOError:
            raise CorruptedFileException("File Error: Nu exista fisierul cu numele dat! ")

        labs = []
        lines = f.readlines()
        for line in lines:
            id_student, nr_lab, nr_problema = [token.strip() for token in line.split(',')]
            lab = Lab(int(id_student), int(nr_lab), nr_problema)
            labs.append(lab)

        f.close()
        return labs

    def __save_to_file(self, labs):
        with open(self.__fileName, 'w') as f:
            for lab in labs :
                lab_string = str(lab.getId_student()) + ',' + str(lab.getNr_lab()) + ',' + str(lab.getNr_problema()) + '\n'
                f.write(lab_string)

    def addLab(self, lab):
        """
            Adaugam un laborator la lista de laboratoare
        """
        all_labs = self.__load_from_file()
        if lab in all_labs:
            raise RepoException("Id-ul laboratorului exista deja in lista!")
        all_labs.append(lab)
        self.__save_to_file(all_labs)

    def getLabs(self):
        return self.__load_from_file()
