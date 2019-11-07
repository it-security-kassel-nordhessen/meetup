package de.micromata.demo;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Base64;

public class CreatedSerializedObjects {

	public static void main(String[] args) throws IOException, ClassNotFoundException {
		Person person = new Person();
		person.setFirstName("Heino");
		person.setLastName("Haller");
		person.setAge(35);

		ByteArrayOutputStream serializedArrayObjStream = new ByteArrayOutputStream();
		ObjectOutputStream serializedObjStream = new ObjectOutputStream(serializedArrayObjStream);
		serializedObjStream.writeObject(person);
		serializedObjStream.flush();
		serializedObjStream.close();

		String base64SerializedObject = Base64.getEncoder().encodeToString(serializedArrayObjStream.toByteArray());
		
		System.out.println(base64SerializedObject);
		
		//##################################################################

		byte[] base64SerializedObjectArray = Base64.getDecoder().decode(base64SerializedObject);
		ObjectInputStream deserializedObjStream = new ObjectInputStream(
				new ByteArrayInputStream(base64SerializedObjectArray));
		Person deserializedObject = (Person) deserializedObjStream.readObject();
		deserializedObjStream.close();

//		System.out.println(deserializedObject.getFirstName());
	}

}
