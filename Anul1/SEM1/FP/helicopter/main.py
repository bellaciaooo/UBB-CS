from helicopter.service.helicopter_service import *
from helicopter.ui.console import *

repo = HelicopterRepoFile("helicoptere.txt")
validator = HelicopterValidator()
service = HelicopterService(repo,validator)

console = Console(service)
console.run()