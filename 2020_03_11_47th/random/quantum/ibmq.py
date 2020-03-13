from qiskit import (
        QuantumCircuit,
        QuantumRegister,
        ClassicalRegister,
        QiskitError,
        execute,
        IBMQ,
        BasicAer)
from qiskit.providers.ibmq import least_busy
from qiskit.tools.monitor import job_monitor
from qiskit.visualization import plot_histogram, plot_bloch_multivector
import sys
from qiskit import IBMQ

token = ''
with open('hash_file', 'r') as file:
    token = file.read().replace('\n', '')
    file.close()

IBMQ.save_account(token)
provider = IBMQ.load_account()

# Build a quantum circuit

n = 5  # number of qubits
q = QuantumRegister(n)
c = ClassicalRegister(n)

circuit = QuantumCircuit(q,c)

circuit.h(q[0])
circuit.h(q[1])
circuit.h(q[2])
circuit.h(q[3])
circuit.h(q[4])

circuit.measure(q,c);

# Matplotlib Drawing
colors = {'id': '#ffca64',
  'u0': '#f69458',
  'u1': '#f69458',
  'u2': '#f69458',
  'u3': '#f69458',
  'x': '#a6ce38',
  'y': '#a6ce38',
  'z': '#a6ce38',
  'h': '#00bff2',
  's': '#00bff2',
  'sdg': '#00bff2',
  't': '#ff6666',
  'tdg': '#ff6666',
  'rx': '#ffca64',
  'ry': '#ffca64',
  'rz': '#ffca64',
  'reset': '#d7ddda',
  'target': '#00bff2',
  'meas': '#f070aa'}

style = {'displaycolor':colors}
circuit.draw(output='mpl',filename='rng.pdf',style=style)

# Compile and run the circuit on a real device backend
# See a list of available remote backends
print("\n(IBMQ Backends)")
for backend in provider.backends():
    print(backend.status())

try:
    # select least busy available device and execute.
    least_busy_device = least_busy(provider.backends(simulator=False,n_qubits=5))
except:
    print("All devices are currently unavailable.")

print("\nUsing " + least_busy_device.name())

job = execute(circuit, backend=least_busy_device, shots=1,max_credits=10)
job_monitor(job)
result = job.result()
counts = result.get_counts(circuit)
print("Result :", counts)
plot_histogram(counts).savefig('rng_histo.pdf')

#psi = result.get_statevector(circuit)
#plot_bloch_multivector(psi).savefig('hadamard_bloch.pdf')
