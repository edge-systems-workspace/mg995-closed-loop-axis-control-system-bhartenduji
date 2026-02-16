# 🤝 Contributing Guidelines

Welcome to the **MG995 Closed-Loop Axis Control System** repository.

This project follows structured Git workflows and professional documentation standards.  
All contributors (students) must follow the guidelines below to ensure consistency and maintain quality.

---

# 📌 1. Contribution Workflow

Please follow this step-by-step workflow:

1. Accept the GitHub Classroom assignment.
2. Clone your assigned repository locally.
3. Create meaningful commits while working.
4. Push changes regularly.
5. Ensure your code compiles successfully before final submission.

---

# 🧾 2. Commit Message Format (Mandatory)


Follow [Conventional Commits](https://www.conventionalcommits.org/):

```
<type>(<scope>): <subject>

<body>

<footer>
```

#### Types
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting, no logic change)
- `refactor`: Code refactoring
- `test`: Adding or updating tests
- `chore`: Maintenance tasks

#### Examples
```bash
feat(auth): implement login functionality

- Add LoginForm component
- Add authentication service
- Add tests for login flow

Closes #123

---

fix(search): resolve case-sensitive search issue

The search was not working with uppercase letters.
Now it converts search query to lowercase.

Fixes #145

---

test(ui): add tests for Button component

- Test rendering with different variants
- Test click handlers
- Test disabled state
```

# 📚 3. Documentation Requirements (Doxygen Mandatory)

All submissions must include proper Doxygen documentation.

## 🔹 File-Level Documentation Required

Each `.ino` file must include:

- `@file`
- `@brief`
- `@author`
- `@date`
- `@details`

Example:

```cpp
/**
 * @file main.ino
 * @brief MG995 Closed-Loop Axis Control System
 * @author YOUR_NAME
 * @date YYYY-MM-DD
 *
 * @details
 * Implements PWM-based closed-loop control for MG995 servo motor.
 */

---



