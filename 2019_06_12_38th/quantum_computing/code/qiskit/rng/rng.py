from qiskit import (
        QuantumCircuit,
        ClassicalRegister,
        QuantumRegister,
        execute,
        Aer)
from qiskit.visualization import plot_histogram, plot_bloch_multivector

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

simulator = Aer.get_backend('qasm_simulator')
#job = execute(circuit, simulator, shots=200000)
job = execute(circuit, simulator, shots=1)
result = job.result()
counts = result.get_counts(circuit)
plot_histogram(counts).savefig('rng_histo.pdf')

#psi = result.get_statevector(circuit)
#plot_bloch_multivector(psi).savefig('hadamard_bloch.pdf')
