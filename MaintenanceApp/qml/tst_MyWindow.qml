import QtQuick
import QtTest 1.2

Item {
	width: 800
	height: 600

	MyWindow {
		id: myWindowTest
	}

	TestCase {
		name: "TestButtonClick"
		when: windowShown

		function test_ClickButton() {
			var notSavedText = "Not saved"
			var savedText = "Saved!"

			verify(myWindowTest.saveStatus == notSavedText, "Save status before saving should be '" + notSavedText + "'")
			mouseClick(myWindowTest.saveButton)
			verify(myWindowTest.saveStatus == savedText, "Save status after saving should be '" + savedText + "'")
		}

	}


}
