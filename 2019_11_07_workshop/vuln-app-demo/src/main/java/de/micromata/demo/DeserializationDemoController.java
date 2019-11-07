package de.micromata.demo;

import java.io.ByteArrayInputStream;
import java.io.ObjectInputStream;
import java.util.Base64;

import org.apache.commons.lang3.StringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class DeserializationDemoController {

	Logger logger = LoggerFactory.getLogger(DeserializationDemoController.class);
	
	private static final String DEFAULT_OBJECT = "rO0ABXNyABhkZS5taWNyb21hdGEuZGVtby5QZXJzb24AAAAAAAAAAQIAA0wAA2FnZXQAE0xqYXZhL2xhbmcvSW50ZWdlcjtMAAlmaXJzdE5hbWV0ABJMamF2YS9sYW5nL1N0cmluZztMAAhsYXN0TmFtZXEAfgACeHBzcgARamF2YS5sYW5nLkludGVnZXIS4qCk94GHOAIAAUkABXZhbHVleHIAEGphdmEubGFuZy5OdW1iZXKGrJUdC5TgiwIAAHhwAAAAI3QABUhlaW5vdAAGSGFsbGVy";

	/**
	 * 
	 * 
	 * @param base64Object
	 * @return
	 */
	
	@RequestMapping("/serial-demo")
	public ModelAndView serailDemo(String base64Object) {
		ModelAndView mav = new ModelAndView("serial-demo");
		try {

			Person deserializedObject = null;
			base64Object = StringUtils.trim(base64Object);
			base64Object = StringUtils.deleteWhitespace(base64Object);

			if (StringUtils.isEmpty(base64Object)) {
				mav.addObject("base64TextareaContent", DEFAULT_OBJECT);
				return mav;
			}

			byte[] base64SerializedObjectArray = Base64.getDecoder().decode(base64Object);
			ObjectInputStream deserializedObjStream = new ObjectInputStream(
					new ByteArrayInputStream(base64SerializedObjectArray));

			deserializedObject = (Person) deserializedObjStream.readObject();

			deserializedObjStream.close();

			if (deserializedObject != null) {
				mav.addObject("parsedOutput", "<br /> Vorname: " + deserializedObject.getFirstName() + "<br /> Nachname: "
						+ deserializedObject.getLastName() + "<br /> Alter: " + deserializedObject.getAge());
			}

		} catch (Exception e) {
			mav.addObject("parsedOutput", e.fillInStackTrace());
		}

		mav.addObject("base64TextareaContent", base64Object);
		return mav;
	}
}
