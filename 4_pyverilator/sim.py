from pyverilator import pyverilator as veri
from pprint import pprint

print("---------dir(veri)------------")
pprint(dir(veri))
print("---------dir(ver.PyVerilator)---")
pprint(dir(veri.PyVerilator))

sim = veri.PyVerilator.build("./cnt.v")


print("sim.json_data : ")
print(sim.json_data)
print("sim.io : ")
print(sim.io);
pprint(dir(sim.io))
#print("sim.inputs : ")
#print(sim.inputs);
print("sim.internal_signals : ")
print(sim.internal_signals)
print("sim.internals : ")
print(sim.internals)
pprint(dir(sim.internals))
#print("sim.outputs : ")
#print(sim.outputs)
#print("sim.model : ")
#print(sim.model)
##print("sim.module_name : ")
#print(sim.module_name)
#print("sim.lib : ")
#print(sim.lib)

#pprint(dir(sim))







