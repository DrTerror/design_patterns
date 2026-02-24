/*! ***************************************************************************
 * @file
 * @brief Mediator
 *
 * Defines an object that encapsulates how a set of objects interact.
 * Use when: you want to reduce dependencies between components.
 *
 * Example: ChatMediator handling message exchange between users.
 *
 * https://takaakit.github.io/uml-diagram-for-cpp-design-pattern-examples/behavioral_patterns/mediator/diagram_map.html
 *
 * @author hellfisch
 * @date 2025.06.26
 *
 *****************************************************************************/

/*******************************************************/
/*   I N C L U D E S   */
/*******************************************************/

#include "CommonDefines.h"

#include <iostream>
#include <string>

/*******************************************************/
/*   G L O B A L S   */
/*******************************************************/

/*******************************************************/
/*   C L A S S E S   */
/*******************************************************/

/**
 * The Mediator interface declares a method used by components to notify the
 * mediator about various events. The Mediator may react to these events and
 * pass the execution to other components.
 */
class Component;
class Mediator
{
        public:
    virtual void notify(Component* sender, const std::string& event) = 0;
    virtual ~Mediator()                                              = default;
};

/**
 * The Base Component provides the basic functionality of storing a mediator's
 * instance inside component objects.
 */
class Component
{
        protected:
    Mediator* dialog;

        public:
    Component(Mediator* mediator = nullptr)
        : dialog(mediator)
    {
    }
    virtual void click()
    {
        dialog->notify(this, "click");
    }
    virtual void keypress()
    {
        dialog->notify(this, "keypress");
    }
    virtual ~Component() = default;
};

class Button : public Component
{
        public:
    Button(Mediator* mediator)
        : Component(mediator)
    {
        std::cout << "button.\n";
        this->dialog->notify(this, "button");
    }
};

class Textbox : public Component
{
        public:
    std::string text;

    Textbox(Mediator* mediator)
        : Component(mediator)
    {
        std::cout << "textbox.\n";
        this->dialog->notify(this, "textbox");
    }
    void setText(const std::string& newText)
    {
        text = newText;
    }
    const std::string& getText() const
    {
        return text;
    }
};

class Checkbox : public Component
{
        protected:
    bool checked = false;

        public:
    Checkbox(Mediator* mediator)
        : Component(mediator)
    {
        std::cout << "checkbox.\n";
        this->dialog->notify(this, "checkbox");
    }

    void check()
    {
        checked = !checked;
        dialog->notify(this, "check");
    }

    void setChecked(bool value)
    {
        checked = value;
        dialog->notify(this, "check");
    }

    bool isChecked() const
    {
        return checked;
    }
};

/**
 * Concrete Mediators implement cooperative behavior by coordinating several
 * components (example).
 */
class AuthenticationDialog : public Mediator
{
        private:
    std::string title;
    Checkbox*   loginOrRegisterChkBx;
    Textbox*    loginUsername;
    Textbox*    loginPassword;
    Textbox*    registrationUsername;
    Textbox*    registrationPassword;
    Textbox*    registrationEmail;
    Button*     okBtn;
    Button*     cancelBtn;

        public:
    AuthenticationDialog()
    {
        loginOrRegisterChkBx = new Checkbox(this);
        loginUsername        = new Textbox(this);
        loginPassword        = new Textbox(this);
        registrationUsername = new Textbox(this);
        registrationPassword = new Textbox(this);
        registrationEmail    = new Textbox(this);
        okBtn                = new Button(this);
        cancelBtn            = new Button(this);

        title = "Register";
        showRegistration();
    }

    ~AuthenticationDialog()
    {
        delete loginOrRegisterChkBx;
        delete loginUsername;
        delete loginPassword;
        delete registrationUsername;
        delete registrationPassword;
        delete registrationEmail;
        delete okBtn;
        delete cancelBtn;
    }

    void notify(Component* sender, const std::string& event) override
    {
        if (sender == loginOrRegisterChkBx && event == "check")
        {
            if (loginOrRegisterChkBx->isChecked())
            {
                title = "Log in";
                showLogin();
            }
            else
            {
                title = "Register";
                showRegistration();
            }
            std::cout << "Title changed to: " << title << "\n";
        }

        if (sender == okBtn && event == "click")
        {
            if (loginOrRegisterChkBx->isChecked())
            {
                std::cout << "Attempting login for user: " << loginUsername->getText() << "\n";
                bool found = (loginUsername->getText() == "user" && loginPassword->getText() == "pass");
                if (!found)
                {
                    std::cout << "Login error: Incorrect username or password\n";
                }
                else
                {
                    std::cout << "Login successful\n";
                }
            }
            else
            {
                std::cout << "Registering user: "
                          << registrationUsername->getText()
                          << ", Email: " << registrationEmail->getText() << "\n";
                std::cout << "User registered and logged in\n";
            }
        }

        if (sender == cancelBtn && event == "click")
        {
            std::cout << "Cancel clicked: Closing dialog or clearing fields\n";
            clearFields();
        }
    }

    void showLogin()
    {
        std::cout << "Showing login form\n";
        // In a real UI, show login controls and hide registration controls
    }

    void showRegistration()
    {
        std::cout << "Showing registration form\n";
        // In a real UI, show registration controls and hide login controls
    }

    void clearFields()
    {
        loginUsername->setText("");
        loginPassword->setText("");
        registrationUsername->setText("");
        registrationPassword->setText("");
        registrationEmail->setText("");
    }

    // Expose components for testing interaction
    Checkbox* getLoginOrRegisterCheckbox()
    {
        return loginOrRegisterChkBx;
    }
    Textbox* getLoginUsername()
    {
        return loginUsername;
    }
    Textbox* getLoginPassword()
    {
        return loginPassword;
    }
    Textbox* getRegistrationUsername()
    {
        return registrationUsername;
    }
    Textbox* getRegistrationPassword()
    {
        return registrationPassword;
    }
    Textbox* getRegistrationEmail()
    {
        return registrationEmail;
    }
    Button* getOkButton()
    {
        return okBtn;
    }
    Button* getCancelButton()
    {
        return cancelBtn;
    }
};

int MediatorMain(void)
{
    printf(NEW_LINE NEW_LINE "====== Mediator ====== (%s-%s) ======" NEW_LINE, __DATE__, __TIME__);

    AuthenticationDialog dialog;

    // Simulate user switching to login form
    dialog.getLoginOrRegisterCheckbox()->setChecked(true);

    // Simulate filling login fields
    dialog.getLoginUsername()->setText("user");
    dialog.getLoginPassword()->setText("wrongpass");

    // Simulate clicking OK button (attempt login)
    dialog.getOkButton()->click();

    // Correct password & try again
    dialog.getLoginPassword()->setText("pass");
    dialog.getOkButton()->click();

    // Switch to registration form
    dialog.getLoginOrRegisterCheckbox()->setChecked(false);

    // Fill registration fields
    dialog.getRegistrationUsername()->setText("newuser");
    dialog.getRegistrationPassword()->setText("newpass");
    dialog.getRegistrationEmail()->setText("newuser@example.com");

    // Click OK to register
    dialog.getOkButton()->click();

    // Cancel button click example
    dialog.getCancelButton()->click();

    return 0;
}
