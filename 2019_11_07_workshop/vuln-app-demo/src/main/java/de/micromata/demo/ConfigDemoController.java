package de.micromata.demo;

import java.io.IOException;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

import org.apache.commons.lang3.StringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class ConfigDemoController {

	Logger logger = LoggerFactory.getLogger(ConfigDemoController.class);
	
	@RequestMapping("/config-demo")
	public ModelAndView configDemo(HttpServletRequest request, String username, String password) throws IOException {
		ModelAndView mav = new ModelAndView("config-demo");

		HttpSession session = request.getSession();
		Object attribute = session.getAttribute("loggedin");

		if (attribute != null) {
			mav.addObject("loggedin", "true");
			return mav;
		}

		if (StringUtils.equals(username, "admin") && StringUtils.equals(password, "EeH4U")) {
			mav.addObject("loggedin", "true");
			session.setAttribute("loggedin", "true");
		}

		return mav;
	}
}
