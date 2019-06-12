from qiskit import (
        QuantumCircuit,
        ClassicalRegister,
        QuantumRegister,
        execute,
        Aer)
from qiskit.visualization import plot_histogram, plot_bloch_multivector

# Build a quantum circuit

n = 1  # number of qubits
q = QuantumRegister(n)
c = ClassicalRegister(1)

circuit = QuantumCircuit(q,c)

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

circuit.draw(output='mpl',filename='tabula_rasa.pdf',style=style)

simulator = Aer.get_backend('statevector_simulator')
job = execute(circuit, simulator, shots=1000)
result = job.result()
counts = result.get_counts(circuit)
plot_histogram(counts).savefig('tabula_rasa_histo.pdf')

psi = result.get_statevector(circuit, decimals=3)
plot_bloch_multivector(psi).savefig('tabula_rasa_bloch.pdf')
