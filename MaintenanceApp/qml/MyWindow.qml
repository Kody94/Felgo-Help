import QtQuick
import QtQuick.Controls 2.15
import MaintenanceApp 1.0

Rectangle {
	anchors.centerIn: parent
	visible: true
	width: 100
	height: 100
	anchors.fill: parent

	property string saveStatus: myText.text
	property alias saveButton: myButton
	property int fizzCount: 0

	Fizzbuzz {
		id: fizzbuzz
	}

	Text {
		id: myText
		text: "Not saved"
		anchors.centerIn: parent
	}
	Text {
		id: fizzbuzzText
		text: ""
		anchors.top: myText.bottom
		anchors.horizontalCenter: parent.horizontalCenter

	}

	Rectangle {
		anchors {
			top: fizzbuzzText.bottom
			horizontalCenter: parent.horizontalCenter
		}
		Button {
			id: myButton
			anchors.left: parent.left
			text: "Save"

			background: Rectangle {
				implicitWidth: 100
				implicitHeight: 25
				border.color: "#888"
				radius: 4
				gradient: Gradient {
					GradientStop { position: 0 ; color: myButton.pressed ? "#ccc" : "#eee" }
					GradientStop { position: 1 ; color: myButton.pressed ? "#aaa" : "#ccc" }
				}
			}

			MouseArea {
				anchors.fill: parent
				onClicked: {
					myText.text = "Saved!"
				}
			}
		}

		Button {
			id: fizzButton
			anchors.right: parent.right
			text: "Add to fizzbuzz!"

			background: Rectangle {
				implicitWidth: 100
				implicitHeight: 25
				border.color: "#888"
				radius: 4
				gradient: Gradient {
					GradientStop { position: 0 ; color: fizzButton.pressed ? "#ccc" : "#eee" }
					GradientStop { position: 1 ; color: fizzButton.pressed ? "#aaa" : "#ccc" }
				}
			}

			MouseArea {
				anchors.fill: parent
				onClicked: {
					fizzCount++;
					fizzbuzzText.text = fizzbuzz.generateList(fizzCount).toString();
				}
			}
		}
	}

}
