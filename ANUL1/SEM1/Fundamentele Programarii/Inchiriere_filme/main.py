from Inchiriere_filme.ui.console import *
from Inchiriere_filme.repository.inchiriere_repo import *
from Inchiriere_filme.service.inchiriere_service import *

#film_repo = FilmRepository()
film_repo = FilmRepoFile("filme.txt")
film_validator = FilmValidator()
film_service = FilmService(film_repo, film_validator)

#client_repo = ClientRepository()
client_repo = ClientRepoFile("clienti.txt")
client_validator = ClientValidator()
client_service = ClientService(client_repo, client_validator)

#inchiriere_repo = InchiriereRepository()
inchiriere_repo = InchiriereRepoFile("inchirieri.txt")
inchiriere_validator = InchiriereValidator()
inchiriere_service = InchiriereService(inchiriere_repo,inchiriere_validator,film_repo,film_validator,client_repo,client_validator)

film_generator = FilmGenerator()
client_generator = ClientGenerator()

console = Console(film_service, client_service, inchiriere_service, film_generator, client_generator)
console.run()