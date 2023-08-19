// Import deps
import React from 'react'

// Create interfaces
interface UserListRowUI {
  position: number;
  user: {
    id: number;
    username: string;
    nickname: string;
    rating: number;
  }
  handleUserRemove: (id: number, username: string) => void;
}

// Create BookshelfListRow component
export const UserListRow = (props: UserListRowUI) => (
  <tr className="table-row">
    <td className="table-item">
      {props.position}
    </td>

    <td className="table-item">
      {props.user.username}
    </td>

    <td className="table-item">
      {props.user.nickname}
    </td>

    <td className="table-item">
      {props.user.rating}
    </td>

    <td className="table-item">
      <button
        className="btn btn-remove"
        onClick={() => props.handleUserRemove(props.user.id, props.user.username)}>
        Remove User 
      </button>
    </td>
  </tr>
)