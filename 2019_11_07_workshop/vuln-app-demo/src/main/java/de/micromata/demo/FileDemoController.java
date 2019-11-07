package de.micromata.demo;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.nio.charset.StandardCharsets;

import org.apache.commons.io.FileUtils;
import org.apache.commons.io.IOUtils;
import org.apache.commons.lang3.StringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class FileDemoController {

	Logger logger = LoggerFactory.getLogger(FileDemoController.class);

	@RequestMapping("/file-demo")
	public ModelAndView fileDemo(String wikifile) throws IOException {
		ModelAndView mav = new ModelAndView("file-demo");

		if (StringUtils.isEmpty(wikifile)) {
			return mav;
		}
		URL wikifilePath = this.getClass().getResource("/file-demo/");
		String classpathDir = wikifilePath.getFile();
		classpathDir = StringUtils.substringBefore(classpathDir, ".jar");
		classpathDir = StringUtils.substringBeforeLast(classpathDir, "/");
		classpathDir = StringUtils.removeStart(classpathDir, "file:");
		
		File readFile = new File(classpathDir + "/" + wikifile);
		
		logger.info("test dir: "+classpathDir + "/" + wikifile);
		
		if (readFile.exists()) {
			String fileContent = FileUtils.readFileToString(readFile, StandardCharsets.UTF_8.toString());
			mav.addObject("fileContent", fileContent);
			return mav;
		}

		URL wikifileFileLocation = this.getClass().getResource("/file-demo/" + wikifile);

		InputStream wikifileStream = wikifileFileLocation.openStream();
		mav.addObject("fileContent", IOUtils.toString(wikifileStream,StandardCharsets.UTF_8.toString()));
		return mav;
	}
}
