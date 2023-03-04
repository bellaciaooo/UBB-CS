from Lab_studenti.ui.console import *

student_repo = StudentRepoFile("student.txt")
student_service = StudentService(student_repo)

lab_repo = LabRepoFile("labs.txt")
lab_vali = LabValidator()
lab_service = LabService(lab_repo, lab_vali, student_repo)

console = Console(lab_service, student_service)
console.run()