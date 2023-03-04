from Gestiune_produs.ui.console import *

produs_repo = ProdusRepoFile("produse.txt")
produs_service = ProdusService(produs_repo)

console = Console(produs_service)
console.run()