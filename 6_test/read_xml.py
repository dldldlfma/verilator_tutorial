import sys

from pprint import pprint

import json
import xmltodict

with open(sys.argv[1],"r") as f:
    xmlString = f.read()

info = xmltodict.parse(xmlString)

jsonString = json.dumps(info, indent=4)

print(jsonString)




