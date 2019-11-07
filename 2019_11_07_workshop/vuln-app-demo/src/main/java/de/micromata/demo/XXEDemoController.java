package de.micromata.demo;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.apache.commons.io.IOUtils;
import org.apache.commons.lang3.StringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

@Controller
public class XXEDemoController {

	private static final String XML_PARSED_OUTPUT = "xmlParsedOutput";

	private static final String XML_CONTENT = "xmlContent";
	
	Logger logger = LoggerFactory.getLogger(XXEDemoController.class);

	@RequestMapping("/xxe-demo")
	public ModelAndView getXml(String xmlContent) {
		ModelAndView mav = new ModelAndView("xxe-demo");
		logger.info("getxml");

		try {

			DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();

			if (StringUtils.isEmpty(xmlContent)) {
				InputStream defaultTableStream = this.getClass().getResourceAsStream("/xxe-demo/table-for-xxe-demo.xml");
				mav.addObject(XML_CONTENT, IOUtils.toString(defaultTableStream, StandardCharsets.UTF_8.toString()));
				return mav;
			}

			InputStream inputStream = new ByteArrayInputStream(xmlContent.getBytes());

			Document document = documentBuilder.parse(inputStream);

			NodeList rootNodes = document.getChildNodes();

			String xmlParsedOutput = StringUtils.EMPTY;

			for (int rootNoteCount = 0; rootNoteCount < rootNodes.getLength(); rootNoteCount++) {

				xmlParsedOutput += "<table  class=\"table\">";

				NodeList rowNodes = rootNodes.item(rootNoteCount).getChildNodes();

				for (int i = 0; i < rowNodes.getLength(); i++) {
					Node row = rowNodes.item(i);

					if (row != null) {
						NodeList colNodes = row.getChildNodes();

						xmlParsedOutput += "<tr>";

						for (int j = 0; j < colNodes.getLength(); j++) {

							Node col = colNodes.item(j);

							if (row != null) {
								logger.info(col.getTextContent());
								xmlParsedOutput += "<td>" + col.getTextContent() + "</td>";
							} else {
								xmlParsedOutput += "<td>--</td>";
							}
						}

						xmlParsedOutput += "</tr>";

					}

				}

				xmlParsedOutput += "</table>";

			}

			mav.addObject(XML_CONTENT, xmlContent);
			mav.addObject(XML_PARSED_OUTPUT, xmlParsedOutput);
			return mav;
		} catch (Exception e) {
			mav.addObject(XML_CONTENT, xmlContent);
			mav.addObject(XML_PARSED_OUTPUT, e.fillInStackTrace());
		}

		return mav;
	}

}
