import sys

from pprint import pprint

import json
import xmltodict

with open(sys.argv[1],"r") as f:
    xmlString = f.read()

jsonString = json.dumps(xmltodict.parse(xmlString), indent=4)

print(jsonString)



